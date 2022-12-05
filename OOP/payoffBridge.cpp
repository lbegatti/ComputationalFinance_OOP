//
//  payoffBridge.cpp
//  OOP
//
//  Created by Luca Begatti on 05/12/2022.
//

#include "payoffBridge.hpp"

PayoffBridge::PayoffBridge(const Payoff& thePayoff){
    thePayoffPtr = thePayoff.clone();
}

PayoffBridge::~PayoffBridge(){
    delete thePayoffPtr;
}

PayoffBridge::PayoffBridge(const PayoffBridge& original){
    thePayoffPtr = original.thePayoffPtr -> clone();
}

PayoffBridge& PayoffBridge::operator=(const PayoffBridge& original){
    if (this != &original) {
        delete thePayoffPtr;
        thePayoffPtr = original.thePayoffPtr -> clone();
    }
    return *this;
}

Payoff* PayoffBridge::operator->()const{
    return thePayoffPtr;
}
