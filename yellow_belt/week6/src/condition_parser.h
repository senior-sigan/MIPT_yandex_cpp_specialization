#pragma once

#include <istream>
#include <memory>

class Node;

std::shared_ptr<Node> ParseCondition(std::istream& is);
