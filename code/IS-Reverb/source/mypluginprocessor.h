//------------------------------------------------------------------------
// Copyright(c) 2024 fhw.
//------------------------------------------------------------------------

#pragma once

#include "public.sdk/source/vst/vstaudioeffect.h"
#include "myplugincids.h"

namespace fhw {

//------------------------------------------------------------------------
//  CReverbProcessor
//------------------------------------------------------------------------
class CReverbProcessor : public Steinberg::Vst::AudioEffect
{
public:
	CReverbProcessor ();
	~CReverbProcessor () SMTG_OVERRIDE;

    // Create function
	static Steinberg::FUnknown* createInstance (void* /*context*/) 
	{ 
		return (Steinberg::Vst::IAudioProcessor*)new CReverbProcessor; 
	}

	//--- ---------------------------------------------------------------------
	// AudioEffect overrides:
	//--- ---------------------------------------------------------------------
	/** Called at first after constructor */
	Steinberg::tresult PLUGIN_API initialize (Steinberg::FUnknown* context) SMTG_OVERRIDE;
	
	/** Called at the end before destructor */
	Steinberg::tresult PLUGIN_API terminate () SMTG_OVERRIDE;

	/** Switch the Plug-in on/off */
	Steinberg::tresult PLUGIN_API setActive (Steinberg::TBool state) SMTG_OVERRIDE;

	/** Will be called before any process call */
	Steinberg::tresult PLUGIN_API setupProcessing (Steinberg::Vst::ProcessSetup& newSetup) SMTG_OVERRIDE;
	
	/** Asks if a given sample size is supported see SymbolicSampleSizes. */
	Steinberg::tresult PLUGIN_API canProcessSampleSize (Steinberg::int32 symbolicSampleSize) SMTG_OVERRIDE;

	/** Here we go...the process call */
	Steinberg::tresult PLUGIN_API process (Steinberg::Vst::ProcessData& data) SMTG_OVERRIDE;
		
	/** For persistence */
	Steinberg::tresult PLUGIN_API setState (Steinberg::IBStream* state) SMTG_OVERRIDE;
	Steinberg::tresult PLUGIN_API getState (Steinberg::IBStream* state) SMTG_OVERRIDE;

//------------------------------------------------------------------------
protected:
    // Include parameters to be modified by VST here

	// mReverbGain refers to the final stage of processing - how loud/soft should the output signal be after it has been manipulated
    Steinberg::Vst::ParamValue mReverbGain = 1.0f;

	// mReverbDecayGain provides the decay amount that the signal should be subject to after each delay
	Steinberg::Vst::ParamValue mReverbDecayGain = 0.45f;

	// mBuffer refers to the buffer itself that contains the delayed signal
	float** mBuffer;

	Steinberg::int32 mBufferPos;
};

//------------------------------------------------------------------------
} // namespace fhw
