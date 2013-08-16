plainopts
=========

plainOpts - plain  option parsing from the command-line 

WARNING: WORK IN PROGRESS


Usage
-----

The idea is simple:

1.  create an plainopts object 
2.  tell plainopts about flags, options and supported arguments
3.  parse argv
4.  react

This is an example usage case:

```cpp
/* definition */
PlainOpts popts; 
popts.add_option<string>(plainopts::MANDATORY, "o", "ohmygodtheykilled");
popts.add_flag(plainopts::OPTIONAL, "f");
popts.set_help("f", "you screwed this one up!");

/* parse after definition */
if (!popts.parse(argc,argv)) {
    cout << "failed parsing" << endl;
}

/* usage */
if (popts.is_set("f") && (popts.get<string>("o") == "kenny")) {
    cout << "you bastards!!!" << endl;
}
```

Declaring a flag
----------------

A flag is an option without an value:
    ./program -v

Using our lib you would define an optional flag ('v') as follows:
    PlainOpts popts;
    popts.add_flag(plainopts:OPTIONAL, "v");



Declaring an option
-------------------

An option is a flag with a value:
    ./program -v 4

Using our lib you would define the option ('v') as follows:
    PlainOpts popts;
    popts.add_option<int>(plainopts:OPTIONAL, "v");
    ....
    if (popts.get<int>("v") == 4) { ... }

This tells the lib that the value for the option 'v' is of type int and should be treated as such.



Declaring an argument
---------------------

TODO
