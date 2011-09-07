SPEC = Gem::Specification.new do |s|
  s.name          = "redtree"
  s.summary       = "Redtree parses Ruby code and returns the parse tree with token locations" 
  s.description   = <<-eof
    Redtree is a low-level Ruby parsing library which extracts the entire concrete Ruby
    parse tree, including the full lexeme stream. It does so with speed and memory
    concerns in mind and uses compact representations wherever possible.
  eof
  s.version       = "1.0.0"
  s.date          = "2011-09-07"
  s.authors       = ["Michael Edgar"]
  s.email         = "adgar@carboni.ca"
  s.homepage      = "https://github.com/michaeledgar/redtree"
  s.files         = Dir["{lib,test}/**/*"] + ['Rakefile', 'README.md', 'LICENSE'] +
                    Dir['ext/redtree/tools/*'] + Dir['ext/redtree/extra/*'] +
                    ['ext/redtree/lex.c', 'ext/redtree/redtree.y', 'ext/redtree/eventids2.c',
                     'ext/redtree/tree.h', 'ext/redtree/tree.c', 'ext/redtree/extconf.rb',
                     'ext/redtree/redtree.h', 'ext/redtree/depend']
  s.test_files    = Dir['test/test_*.rb']
  s.require_paths = ['lib', 'ext']
  s.extensions    = ['ext/redtree/extconf.rb']
  s.has_rdoc      = false
  s.required_ruby_version = '~> 1.9.2'
end