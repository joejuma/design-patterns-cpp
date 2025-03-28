# Design Patterns Reference (C++)

## About
This repository is a collection of C++ reference implementations, demonstrating various design patterns.

## Paterns
| Pattern Name | Description | Source (Personally) | Directory |
|--------------|-------------|--------|------|
| Service Locator | A program-scoped object that can be used to fetch references to other objects. Reduces passing object references through many functions. |  "Massively Multiplayer Game Development" (Thor Alexander, 2003) | `service-locator` |

## Motivations
In my experience most programmers have heard of the [Gang of Four](https://en.wikipedia.org/w/index.php?title=Gang_of_Four_(software)&redirect=no) ("GoF") and their design patterns. However far fewer programmers ever read the book they derived the original idea from [A Pattern Language](https://en.wikipedia.org/wiki/A_Pattern_Language) ("APL"). In APL the authors lay out (what I believe to be) a more comprehensive description of the benefits of design patterns. In addition to their benefits, they suggest layering them, and that each pattern is a solution to a specific problem. Some patterns are also built from other patterns. The remainder of the book is spent detailing patterns for architecture, as the authors' goals are to catalogue those they had collectively seen as a contribution to the field's corpus.

My goal here is to supplement the GoF's well-known patterns with additional patterns I've employed or come across, complete with reference implementations. Generally these patterns are a bit more complex, or uncommon than the GoF patterns which are more of central patterns to the most common programming problems across many languages.

## License
Please see `license.md` for the terms of use.