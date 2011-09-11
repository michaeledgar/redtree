#
# $Id: sexp.rb 31342 2011-04-25 02:28:49Z naruse $
#
# Copyright (c) 2004,2005 Minero Aoki
#
# This program is free software.
# You can distribute and/or modify this program under the Ruby License.
# For details of Ruby License, see ruby/COPYING.
#

require_relative 'core'

class Redtree
  class Ripper
    class Node < Array
      attr_reader :parse_node
      def initialize(body, parse_node)
        replace(body)
        @parse_node = parse_node
        @source_start = nil
        @source_stop = nil
      end

      def source_start
        @source_start ||= parse_node.source_start
        return @source_start
      end

      def source_stop
        @source_stop ||= parse_node.source_stop
        return @source_stop
      end
    end

    class Token < Array
      attr_reader :parse_node
      def initialize(body, parse_node)
        replace(body)
        @parse_node = parse_node
      end

      def size
        self[1].size
      end

      def source_start
        loc = self[2]
        Location.new(loc[0], loc[1])
      end

      def source_stop
        loc = self[2]
        Location.new(loc[0], loc[1] + size - 1)
      end
    end

    # [EXPERIMENTAL]
    # Parses +src+ and create S-exp tree.
    # Returns more readable tree rather than Ripper.sexp_raw.
    # This method is for mainly developper use.
    #
    #   require 'ripper'
    #   require 'pp'
    #
    #   pp Ripper.sexp("def m(a) nil end")
    #     #=> [:program,
    #          [[:def,
    #           [:@ident, "m", [1, 4]],
    #           [:paren, [:params, [[:@ident, "a", [1, 6]]], nil, nil, nil, nil]],
    #           [:bodystmt, [[:var_ref, [:@kw, "nil", [1, 9]]]], nil, nil, nil]]]]
    #
    def Ripper.sexp(src)
      SexpBuilderPP.new(src).parse
    end

    # [EXPERIMENTAL]
    # Parses +src+ and create S-exp tree.
    # This method is for mainly developper use.
    #
    #   require 'ripper'
    #   require 'pp'
    #
    #   pp Ripper.sexp_raw("def m(a) nil end")
    #     #=> [:program,
    #          [:stmts_add,
    #           [:stmts_new],
    #           [:def,
    #            [:@ident, "m", [1, 4]],
    #            [:paren, [:params, [[:@ident, "a", [1, 6]]], nil, nil, nil]],
    #            [:bodystmt,
    #             [:stmts_add, [:stmts_new], [:var_ref, [:@kw, "nil", [1, 9]]]],
    #             nil,
    #             nil,
    #             nil]]]]
    #
    def Ripper.sexp_raw(src)
      SexpBuilder.new(src).parse
    end

    class SexpBuilderPP < Ripper   #:nodoc:
      private

      PARSER_EVENT_TABLE.each do |event, arity|
        if /_new\z/ =~ event.to_s and arity == 0
          module_eval(<<-End, __FILE__, __LINE__ + 1)
            def on_#{event}
              Node.new([], curnode())
            end
          End
        elsif /_add\z/ =~ event.to_s
          module_eval(<<-End, __FILE__, __LINE__ + 1)
            def on_#{event}(list, item)
              list.push item
              Node.new(list, curnode())
            end
          End
        else
          module_eval(<<-End, __FILE__, __LINE__ + 1)
            def on_#{event}(*args)
              Node.new([:#{event}, *args], curnode())
            end
          End
        end
      end

      SCANNER_EVENTS.each do |event|
        module_eval(<<-End, __FILE__, __LINE__ + 1)
          def on_#{event}(tok)
            Token.new([:@#{event}, tok, [lineno(), column()]], curnode())
          end
        End
      end
    end

    class SexpBuilder < Ripper   #:nodoc:
      private

      PARSER_EVENTS.each do |event|
        module_eval(<<-End, __FILE__, __LINE__ + 1)
          def on_#{event}(*args)
            args.unshift :#{event}
            Node.new(args, curnode())
          end
        End
      end

      SCANNER_EVENTS.each do |event|
        module_eval(<<-End, __FILE__, __LINE__ + 1)
          def on_#{event}(tok)
            Token.new([:@#{event}, tok, [lineno(), column()]], curnode())
          end
        End
      end
    end

  end
end