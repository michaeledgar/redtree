#
# $Id: core.rb 25189 2009-10-02 12:04:37Z akr $
#
# Copyright (c) 2003-2005 Minero Aoki
#
# This program is free software.
# You can distribute and/or modify this program under the Ruby License.
# For details of Ruby License, see ruby/COPYING.
#

require File.dirname(__FILE__) + '/../../ext/redtree/redtree.so'

class Redtree

  # Parses Ruby program read from _src_.
  # _src_ must be a String or a IO or a object which has #gets method.
  def Redtree.parse(src, filename = '(ripper)', lineno = 1)
    new(src, filename, lineno).parse
  end

  def warn(fmt, *args)
  end
  def warning(fmt, *args)
  end
end