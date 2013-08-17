#ifndef PLAINOPTS
#define PLAINOPTS 1

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;


namespace plainopts {

  enum Settings { OPTIONAL=0, MANDATORY=1 };

  /*****************************************************************************
  * A Flag contains no value and is always optional.
  * It's either set or not.
  */
  class Flag {
  
  private:
    char shortName;
    string longName;
    string helpText;
    bool isSet;

  public:
    Flag (char cName) : shortName(cName) {
      longName = "";
      helpText = "";
    }

    Flag (string lName) : longName(lName) {
      shortName = '\0';
      helpText = "";
    }

    Flag (char sName, string lName) : shortName(sName), longName(lName) {
      helpText = "";
    }

    /// make this class polymorph
    ~Flag() { }

    inline void set_help(string text) { helpText = text; }
    inline string get_help() { return helpText; }
    inline bool is_set() { return isSet; }
  };


  /*****************************************************************************
  * Every option has a value associated with it. 
  * TODO: allow more than one value
  */
  class Option : public Flag {
  private:
    string parameter;
    bool mandatory;

  public:
    Option(char sName) : Flag(sName) { }
    Option(string lName) : Flag(lName) { }
    Option(char sName, string lName) : Flag(sName, lName) { }
    ~Option(){ }

    inline void set_parameter(string value) {
      parameter = value;
    }
    inline void set_mandatory(bool value) {
      mandatory = value;
    }

    inline bool is_mandatory() {
      return mandatory;
    }


    template <class T>
    T get_value() {
      T returnValue;
      stringstream ss(stringstream::in | stringstream::out);
      ss << parameter;
      ss >> returnValue;

      // TODO: check if parsing failed

      return returnValue;
    }

  };



  /*****************************************************************************
  * This is the container for the flag and options
  */
  class Plainopts {

  private:
    map<string, Flag*> available_entries;
    set<string> defined_flags;

    bool is_available(string key) {
      return available_entries.count(key) > 0;
    }



  public:
    Plainopts() { }

    /// adds a new flag option to the internal datastructures using the key
    void add_flag(char sName, string lName) {

      // don't allow empty names
      if (sName == '\0' && lName == "") { return; }

      Flag *new_flag = new Flag(sName, lName);
      string key;

      // add with short name if not empty
      if (sName != '\0') {
        key = sName;
        available_entries.insert(pair<string, Flag*>(key, new_flag));
      }

      // add with long name if not empty
      if (lName != "") {
        key = lName;
        available_entries.insert(pair<string, Flag*>(key, new_flag));
      }
    }

    ///  sets the help text on the object with long name as a key
    void set_help(string key, string text) {
      map<string, Flag*>::iterator it;
      if (is_available(key)) {
        it = available_entries.find(key);
        (*it).second->set_help(text);
      }
    }

    /// sets the help text on the object with short name as a key
    void set_help(char key, string text) {
      string keyAsString;
      keyAsString = key;
      set_help(keyAsString, text);
    }
  };

} /* namespace */

#endif /* PLAINOPTS */