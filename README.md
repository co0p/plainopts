plainopts
=========

plainOpts - plain  option parsing from the command-line 



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

