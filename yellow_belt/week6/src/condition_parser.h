#pragma once

#include <memory>
#include <istream>

using namespace std;

class Node;

shared_ptr<Node> ParseCondition(istream& is);
