#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

// treenode
struct HtmlElement {
  string name;
  string text;
  vector <HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement() {}
  // ref
  HtmlElement(const string &name, const string &text) : name(name), text(text) {}

  string str(int indent = 0) const {
    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0)
      oss << string(indent_size * (indent + 1), ' ') << text << endl;
    // range-based for loop
    // negligent
    for (const auto &e : elements)
      oss << e.str(indent + 1);
    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

};

struct HtmlBuilder {
  HtmlBuilder(string root_name) {
    root.name = root_name;
  }

  // void add_child(string child_name, string child_text) {
  //   HtmlElement html{child_name, child_text};
  //   // in-place push_back(temp mov str into container) class/struct
  //   root.elements.emplace_back(html);
  // }

  HtmlBuilder &add_child(string child_name, string child_text) {
    HtmlElement html{child_name, child_text};
    // in-place push_back(temp mov str into container) class/struct
    root.elements.emplace_back(html);
    return *this;
  }
  HtmlElement root;
};

int main(int argc, char const *argv[]) {
  /* code */

  HtmlBuilder builder("ul");
  // builder.add_child("li", "hello");
  // builder.add_child("li", "world");
  builder.add_child("li", "hello").add_child("li", "world");

  cout << builder.root.str() << endl;

  ostringstream oss1;

  oss1 << "Hello, world" << endl;
  oss1 << "42" << std::endl;
  cout << oss1.str();
  return 0;
}




// end
