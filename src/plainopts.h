#ifndef PLAINOPTS
#define PLAINOPTS 1

#include <string>
using namespace std;


namespace plainopts {

  enum Settings { OPTIONAL, MANDATORY };

  /**
  * A Flag contains no value. It's either set or not.
  */
  class Flag {
  
  private:
    string shortName;
    string longName;
    bool mandatory;
    string helpText;

  public:
    /// constructor needs at least a short name
    Flag(string sName, string lName = "") {
      shortName = sName;
      longName = lName;
      mandatory = false;
      helpText = "";
    }

    /// make this class polymorph
    ~Flag() { }

    inline void set_mandatory(bool value) { mandatory = value; }
    inline void set_help(string text) { helpText = text; }

    inline bool is_mandatory() { return mandatory; }
    inline string get_help() { return helpText; }

  };


} /* namespace */

#endif /* PLAINOPTS */