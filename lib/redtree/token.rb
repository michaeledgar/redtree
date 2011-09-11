class Redtree
  class Tree
    class Token
  	  def inspect
  	    "<Redtree::Tree::Token #{name} line=#{line_number} col=#{column} size=#{size}>"
  	  end

  	  def pretty_print(q)
  	  	q.text "<Token #{name} #{line_number}:#{column}-#{column+size}>"
  	  end

      # Ranges are Dijkstra-style (Ruby's ... operator)
      def source_start
        Location.new(line_number, column)
      end

      def source_stop
        Location.new(line_number, column + size)
      end
  	end
  end
end