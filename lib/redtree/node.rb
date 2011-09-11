class Redtree
  class Tree
    class Node
  	  def inspect
  	    "<Redtree::Tree::Node #{name}>"
  	  end

  	  def children
  	  	size.times.map { |i| self[i] }
  	  end

  	  def pretty_print(q)
  	  	space = size > 0 ? ' ' : ''
  	  	q.group(1, "<Node #{name}#{space}", ">") {
  	  	  q.seplist(children, lambda { q.text "," }) { |v|
  	  	  	q.breakable ''
  	  	  	q.pp v
  	  	  }
  	  	}
  	  end

      def source_start
        return @source_start if (@source_start ||= nil)
        children.each do |child|
          if (start = child.source_start)
            @source_start = start
            break
          end
        end
        return @source_start
      end

      def source_stop
        return @source_stop if (@source_stop ||= nil)
        children.reverse_each do |child|
          if (start = child.source_stop)
            @source_stop = start
            break
          end
        end
        return @source_stop
      end
  	end
  end
end