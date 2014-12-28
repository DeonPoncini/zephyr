---
Title: zephyr
Description: Light C++ utilities
Author: Deon Poncini

---
zephyr
===============

Developed by Deon Poncini <dex1337@gmail.com>

Description
-----------
A small collection of useful C++ utility functions

Building
--------
Use the [scripts](http://github.com/DeonPoncini/scripts) build system to build
this library, just add zephyr to your manifest xml file with the appropriate
remote

Usage
-----
* CExport: Helpers to convert namespaces for C code
* ConditionVariable: Pass data between threads with locking
* cstring: Helper functions to convert between std::string and c strings
* Either: An either type for built in types
* make\_unique: C++14 implementation of make\_unique
* QueueLoop: Push data between threads on a queue
* Random: Simple dice/coin based random functions
* Timestamp: Log timestamps at different resolutions
* to\_string: C++11 implementation of std::to\_string

License
-------
Copyright (c) 2014 Deon Poncini.
See the LICENSE file for license rights and limitations (MIT)
