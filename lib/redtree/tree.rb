class Redtree
  # This class encapsulates an entire parse tree. It has a root as well as the
  # full lexeme stream.
  class Tree
    def pretty_print(q)
      root.pretty_print(q)
    end
  end
end