//
//  PS_AudioUnits.h
//  PedalStack
//
//  Created by Lipstick on 10/24/16.
//  Copyright © 2016 Deepak Chennakkadan. All rights reserved.
//

#ifndef PS_Effects_h
#define PS_Effects_h

// Core Audio
#import <CoreAudio/CoreAudio.h>
#import <AudioToolbox/AudioToolbox.h>

// Audio Units
#import <AudioUnit/AudioUnitParameters.h>
#import <AudioUnit/AudioUnitProperties.h>

// C++ std libs
#include <iostream>
#include <vector>

class PS_Effects
{
public:
    // Constructor & Destructor
    ~PS_Effects(){}
    PS_Effects(){}
    PS_Effects(UInt32 effect, AUGraph graph, AUNode outNode, AudioStreamBasicDescription streamDesc);
    
    // Getters
    AUNode GetEffectNode();
    AudioComponentDescription GetEffectDescription();
    UInt32 GetEffectID();
    AudioUnit GetEffectAU();
    void GetEffectInfo();
    
    // Setters
    void SetEffectParameter(AudioUnitParameterID paramID, AudioUnitParameterValue paramVal);
    void SetStreamDescription(AudioUnit outAU);
    
    // Input Output
    void ConnectEffectIO(AUNode input, AUNode output, UInt32 inBus = 0, UInt32 outBus = 0);
    void DisconnectEffectIO();
    
    
private:
    // Error Checking
    enum ErrorType
    {
      NodeAdded,
      NodeConnected,
      NodeInfo,
      NodeParameter,
      NodeSetProperty,
      NodeGetProperty    
    } _ErrorType;
    
    
    
    UInt32 _effectID;
    AUGraph _graph;
    AUNode _output;
    
    AudioUnit _effectAU;
    AUNode _effectNode;
    AudioComponentDescription _effectDesc;
    AudioStreamBasicDescription _streamDesc;
    
    OSStatus _result;
    
    void FillDescription();
    void AddEffectNode();
    
    // Error Checking
    void ErrorCheck(ErrorType error);
    void PrintStreamDescription();
    
};


#endif /* PS_Effects_h */
