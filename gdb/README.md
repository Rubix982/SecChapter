# GDB

A section dedicated for `gdb` information.

## Summary

`GDB` helps with seeing the "inside" of another proram while it executes (during runtime), or what another program was doing at the moment it crashed.

## Use Cases

* Start your program, specifying anything that might affect its behavior
* Make your program stop on specified conditions
* Examine what has happened, when your program has stopped
* Change things in your program, so you can experiment with correcting the effects of one bug and go on to learn about another

## Language Support

We can use `GDB` to debug programs written in,

* `C`
* `C++`
* `Pascal` (programs which use `sets`, `subranges`, `file variables`, or `nested functions` does not currently work. GDB does not support entering expressions, printing values, or similar features using `Pascal` syntax)
* `Fortran` (it may be necessary to refer to some variables with a trailing underscore)
* `Objective-C` (using either the Apache/NeXT or the GNU Objective-C runtime)


