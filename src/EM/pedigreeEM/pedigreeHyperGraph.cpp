#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/document.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/writer.h"
#include "/Users/Eddie/rapidjson/include/rapidjson//prettywriter.h"
#include "/Users/Eddie/rapidjson/include/rapidjson/stringbuffer.h"
#include <boost/algorithm/string.hpp>


LogVar RootAncestorProbFunction::operator()(Node* node, unsigned x) {
    return _pedigree->getRootProb((Person*)node,x);
}

