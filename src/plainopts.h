#ifndef PLAINOPTS
#define PLAINOPTS 1

#include <string>
#include <sstream>

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

} /* namespace */

#endif /* PLAINOPTS */