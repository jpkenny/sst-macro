#include "boxml.h"
#include <sstmac/common/sstmac_config.h>

using namespace std;
using namespace tinyxml2;

namespace lblxml
{
#ifdef SSTMAC_HAVE_BOOST
void
erase_all(std::string& str, const char* delim){
  boost::erase_all(str, delim);
}
#else
void
erase_all(std::string& str, const char* delim){
#error Not yet implemented
}
#endif

  void read_box(XMLElement* element, int debug);
  void read_comm_event(XMLElement* element, int debug);
  void read_coll_event(XMLElement* element, int debug);
  void read_comp_event(XMLElement* element, int debug);
  void populate_listeners();

  int get_index(string& id) {
    erase_all(id, "B");
    erase_all(id, "e");
    return atoi( id.c_str() );
  }

  int get_index(const char* cstr){
    std::string str = cstr;
    return get_index(str);
  }

  int count_xml(tinyxml2::XMLDocument* doc,
                const string& level1,
                const string& level2) {

    /**
    TODO debug_ is not defined
    if (debug_ > 1) {
      cout << "Reading " << level1
                        << " of type " << level2 << "\n";
    }
    */

    int count = 0;

    XMLElement* e1 = doc->FirstChildElement( level1.c_str() );
    if (!e1) {
      cerr << "can't find " << level1 << "\n";
      abort();
    }
    XMLElement* e2 = e1->FirstChildElement( level2.c_str() );
    if (!e2) {
      cerr << "can't find first " << level2 << "\n";
      abort();
    }
    XMLElement* elast = e1->LastChildElement( level2.c_str() );
    if (!elast) {
      cerr << "can't find last " << level2 << "\n";
      abort();
    }
    while (e2 != elast) {
      ++count;
      e2 = e2->NextSiblingElement( level2.c_str() );
    }
    ++count;

    return count;
  }

  void boxml::process_xml(tinyxml2::XMLDocument* doc,
                         string level1, string level2,
                         void (*fp)(XMLElement*,int))
  {
    if (debug_ > 1) {
      cout << "Reading " << level1
                        << " of type " << level2 << "\n";
    }
    XMLElement* e1 = doc->FirstChildElement( level1.c_str() );
    if (!e1) {
      cerr << "can't find " << level1 << "\n";
      abort();
    }
    XMLElement* e2 = e1->FirstChildElement( level2.c_str() );
    if (!e2) {
      cerr << "can't find first " << level2 << "\n";
      abort();
    }
    XMLElement* elast = e1->LastChildElement( level2.c_str() );
    if (!elast) {
      cerr << "can't find last " << level2 << "\n";
      abort();
    }
    static int eventnum = 0;
    while (e2 != elast) {
      if (eventnum % 1000000 == 0){
        printf("Processing event %d\n", eventnum);
        fflush(stdout);
      }
      eventnum++;
      (*fp)(e2,debug_);
      e2 = e2->NextSiblingElement( level2.c_str() );
    }
    (*fp)(elast,debug_);
  }

  void read_box(XMLElement* element, int debug) {
    string boxid = element->Attribute("id");
    int index = get_index(boxid);
    int loc = element->IntAttribute("loc");
    box* b = new box(index, boxid, loc);
    g_boxes[index] = b;
    if (debug > 1) b->print();
  }

  void read_comm_event(XMLElement* element, int debug) {
    string eventid = element->Attribute("id");
    int index = get_index(eventid);
    string dep = element->Attribute("dep");
    int from = get_index( element->Attribute("from") );
    int to = get_index( element->Attribute("to") );
    int size = element->IntAttribute("size");
    comm* ev = new comm(index, eventid, dep, "uninitialized", from, to, size );
    if (index >= g_events.size()){
      spkt_throw_printf(sprockit::value_error,
        "event id %d is greater than max %d - check XML file for largest event id",
        index, g_events.size());
    }
    g_events[index] = ev;
    if (debug > 1) g_events[index]->print();
  }

  void read_coll_event(XMLElement* element, int debug) {
    string eventid = element->Attribute("id");
    int index = get_index(eventid);
    string dep = element->Attribute("dep");
    //string type = element->Attribute("type");
    int size = element->IntAttribute("size");
    reduce* commev = new reduce(index, eventid, dep, size);
    if (index >= g_events.size()){
      spkt_throw_printf(sprockit::value_error,
        "event id %d is greater than max %d - check XML file for largest event id",
        index, g_events.size());
    }
    g_events[index] = commev;
    commev->add_team( element->Attribute("team") );
    commev->compute_box_array();
    if (debug > 1) commev->print();
    fflush(stdout);
  }

  void read_comp_event(XMLElement* element, int debug) {
    string eventid = element->Attribute("id");
    int index = get_index(eventid);
    string dep = element->Attribute("dep");
    int at = get_index( element->Attribute("at") );
    double time = element->DoubleAttribute("time");
    comp* ev = new comp(index, eventid, dep, "uninitialized", -1, time, at );
    if (index >= g_events.size()){
      spkt_throw_printf(sprockit::value_error,
        "event id %d is greater than max %d - check XML file for largest event id",
        index, g_events.size());
    }
    g_events[index] = ev;
    if (debug > 1) g_events[index]->print();
  }

}