#ifndef HMHM_H
#define HMHM_H


class HMHM {
public:
    virtual void train(const vector<DirectedHypergraph>& trainingSet) = 0;
    virtual void predict(const DirectedHypergraph& test) = 0;
};

#endif