#!ruby -s

require 'mkmf'
require 'rbconfig'
require 'fileutils'

def main
  unless find_executable('bison')
    unless File.exist?('redtree.c') or File.exist?("#{$srcdir}/redtree.c")
      Logging.message 'missing bison; abort'
      return
    end
  end
  $objs = %w(redtree.o)
  $cleanfiles.concat %w(redtree.c redtree.output y.output eventids1.c)
  $defs << '-DREDTREE'
  $defs << '-DREDTREE_DEBUG' if $debug
  $VPATH = []
  $INCFLAGS << ' -I$(srcdir)/extra'
  create_makefile 'redtree'
end

main
