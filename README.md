Redtree: A Superior Ruby Parser
===============================

**Homepage**:     [http://carboni.ca/projects/p/redtree](http://carboni.ca/)      
**Git**:          [https://github.com/michaeledgar/redtree](http://github.com/michaeledgar/redtree)   
**Author**:       Michael Edgar    
**Copyright**:    2011   
**License**:      MIT    
**Latest Version**: none   
**Release Date**: None, yet.

Synopsis
--------

Redtree is a Ruby parser in the spirit of Ripper and Melbourne, but with additional capabilities. It carries with it the entire shift-reduce sequence and token boundaries, so a consumer of a Redtree parse tree knows exactly where each token occurred.

Redtree was borne out of the [Laser](https:/github.com/michaeledgar/laser) project, which needs to be able to rewrite source code token-by-token (including whitespace, a typically ignored token) for proper style-linting. It is also difficult to extract correct line numbers from a Ripper parse tree, and impossible to reliably obtain column numbers from Ripper or Melbourne. Hence: Redtree.

Feature List
------------
                                                                              
Details are always forthcoming, but:

**1. Full Token Information**: Each internal node of the parse tree knows exactly which tokens (or other internal nodes) composed the node's reduction during parsing. Every token is available, including its line/column start and end points.  
**2. Comment Nodes**: Attaching comments to nodes is a task required of documentation tools, linters, static analyzers, and so on. Yet no Ruby parser adequately includes comments when necessary.  
**3. Compact Representation**: Including this much information is possible with a compact, simple representation. Redtree incorporates this design to minimize its space use.    
**4. Fast Parsing**: Parsing should be fast. Before converting to a more natural AST, Redtree runs at least 40% faster than Ripper. Of course, Ripper does more work converting to a simpler AST, but Redtree is stashing away a *lot* more information.

Installing
----------

To install Redtree, use the following command:

    $ gem install redtree --prerelease
    
(Add `sudo` if you're installing to a directory requiring root privileges to write)
                                                                              
Usage
-----

When it works, I'll add it here. I promise.

Changelog
---------

- **Aug.29.2011**: Project initiated.

Copyright
---------

Redtree &copy; 2011 by [Michael Edgar](mailto:adgar@carboni.ca).
Redtree is licensed under the MIT license. See {file:LICENSE}.