class Redtree
  class Tree
    class Token
  	  def inspect
  	    "<Redtree::Tree::Token #{name} line=#{line_number} col=#{column} size=#{size}>"
  	  end

  	  def pretty_print(q)
  	  	q.text "<Token #{name} #{line_number}:#{column}-#{column+size-1}>"
  	  end
  	end
  end
end