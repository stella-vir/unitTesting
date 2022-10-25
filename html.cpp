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

int main(int argc, char const *argv[]) {
  /* code */
  string words[] = {"hello", "world"};
  HtmlElement html{"ul", ""};
  for (auto &w:words)
    html.elements.push_back(HtmlElement{"li", w});
  cout << html.str() << endl;

  ostringstream oss1;

  oss1 << "Hello, world" << endl;
  oss1 << "42" << std::endl;
  cout << oss1.str();
  return 0;
}




// end
