#include "/Users/Eddie/hyperGraphEM/src/EM/pedigreeEM/pedigreeHyperGraph.h"



unordered_set<NuclearFamily*> NuclearFamily::familyToNuclearFamily(const unordered_set<Family*>& famSet) {

    unordered_set<NuclearFamily*> ans;
    for(Family* family: famSet) {
        ans.insert((NuclearFamily*)family);
    }
    return ans;
}


unordered_set<Person*> NuclearFamily::getParents() const {
    return Person::nodeToPerson(Family::getParents());
}
unordered_set<Person*> NuclearFamily::getChildren() const {
    return Person::nodeToPerson(Family::getChildren());
}
unordered_set<Person*> NuclearFamily::getNodes() const {
    return Person::nodeToPerson(Family::getNodes());
}