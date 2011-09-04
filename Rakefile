require 'rubygems'
require 'rake/gempackagetask'
require 'rake/testtask'

WINDOWS = (PLATFORM =~ /win32|cygwin/ ? true : false) rescue false

desc "Builds the gem"
task :gem do
  sh "cd ext/redtree; make clean; rm Makefile; echo"
  load 'redtree.gemspec'
  Gem::Builder.new(SPEC).build
end

desc "Installs the gem"
task :install => :gem do 
  sh "gem install #{SPEC.name}-#{SPEC.version}.gem --no-rdoc --no-ri"
end

desc 'Build the extension'
task :build do
  sh "cd ext/redtree && ruby extconf.rb && make clean && make"
end

Rake::TestTask.new

