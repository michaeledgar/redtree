# $Id: generate.rb 25189 2009-10-02 12:04:37Z akr $

require 'optparse'
require 'set'

def main
  mode = nil
  ids1src = nil
  ids2src = nil
  template = nil
  output = nil

  parser = @parser = OptionParser.new
  parser.banner = "Usage: #{File.basename($0)} --mode=MODE [--ids1src=PATH] [--output=PATH]"
  parser.on('--mode=MODE', 'check, eventids1.') {|m|
    mode = m
  }
  parser.on('--ids1src=PATH', 'A source file of event-IDs 1 (parse.y).') {|path|
    ids1src = path
  }
  parser.on('--output=PATH', 'An output file.') {|path|
    output = path
  }
  parser.on('--help', 'Prints this message and quit.') {
    puts parser.help
    exit true
  }
  begin
    parser.parse!
  rescue OptionParser::ParseError => err
    usage err.message
  end
  usage 'no mode given' unless mode
  case mode
  when 'check'
    usage 'no --ids1src' unless ids1src
    h = read_ids1(ids1src)
    exit 0
  when 'eventids1'
    usage 'no --ids1src' unless ids1src
    result = generate_eventids1(read_ids1(ids1src))
  end
  if output
    File.open(output, 'w') {|f|
      f.write result
    }
  else
    puts result
  end
end

def usage(msg)
  $stderr.puts msg
  $stderr.puts @parser.help
  exit false
end

def camelize(lower_case_and_underscored_word)
  lower_case_and_underscored_word.to_s.gsub(/\/(.?)/) { "::#{$1.upcase}" }.gsub(/(?:^|_)(.)/) { $1.upcase }
end

def constant_name_for_id(id)
  id.split('__').map { |part| camelize(part) }.join('_')
end

def generate_eventids1(ids)
  buf  = "VALUE rb_mNodes;\n"
  buf << "enum redtree_ids {\n"
  ids.each do |id|
    buf << "  redtree_rulenum_#{id},\n"
  end
  buf << "};\n\n"
  buf << "static void\n"
  buf << "redtree_init_eventids1(VALUE self) {\n"
  buf << %Q[  rb_aNames = rb_ary_new2(redtree_rulenum_MAX_RULES);\n]
  buf << %Q[  rb_mNodes = rb_define_module_under(self, "Nodes");\n]
  buf << %Q[  rb_define_const(rb_mNodes, "NAMES", rb_aNames);\n]

  ids.each do |id|
    constant_name = constant_name_for_id(id)
    buf << %Q[  rb_define_const(rb_mNodes, "#{constant_name}", INT2FIX(redtree_rulenum_#{id}));\n]
    buf << %Q[  rb_ary_push(rb_aNames, rb_str_new("#{constant_name}", #{constant_name.size}));\n]
  end

  buf << "}\n"
  buf
end

def read_ids1(path)
  s = Set[]
  File.open(path) {|f|
    f.each do |line|
      next if /\A\#\s*define\s+s?reduce_rule/ =~ line
      line.scan(/reduce_rule\((\w+)/) do |event|
        s << event[0]
      end
    end
  }
  ['UNUSED'] + s.to_a + ['MAX_RULES']
end

main
