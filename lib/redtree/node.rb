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
  	end
  end
end