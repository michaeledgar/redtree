class Redtree
  class Location < Array
    def initialize(line, col)
      replace([line, col])
    end

    def line
      self[0]
    end

    def col
      self[1]
    end
  end
end