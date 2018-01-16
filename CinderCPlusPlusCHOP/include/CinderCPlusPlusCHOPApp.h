#pragma once

#include "CHOP_CPlusPlusBase.h"

// To get more help about these functions, look at CHOP_CPlusPlusBase.h
class CinderCPlusPlusCHOPApp : public CHOP_CPlusPlusBase
{
public:
	CinderCPlusPlusCHOPApp(const OP_NodeInfo* info);
	virtual ~CinderCPlusPlusCHOPApp();

	virtual void		getGeneralInfo(CHOP_GeneralInfo* ) override;
	virtual bool		getOutputInfo(CHOP_OutputInfo*) override;
	virtual const char*	getChannelName(int32_t index, void* reserved) override;

	virtual void		execute(const CHOP_Output*,
		OP_Inputs*,
		void* reserved) override;


	virtual int32_t		getNumInfoCHOPChans() override;
	virtual void		getInfoCHOPChan(int index,
		OP_InfoCHOPChan* chan) override;

	virtual bool		getInfoDATSize(OP_InfoDATSize* infoSize) override;
	virtual void		getInfoDATEntries(int32_t index,
		int32_t nEntries,
		OP_InfoDATEntries* entries) override;

	virtual void		setupParameters(OP_ParameterManager* manager) override;
	virtual void		pulsePressed(const char* name) override;

private:

	// We don't need to store this pointer, but we do for the example.
	// The OP_NodeInfo class store information about the node that's using
	// this instance of the class (like its name).
	const OP_NodeInfo*	myNodeInfo;

	// In this example this value will be incremented each time the execute()
	// function is called, then passes back to the CHOP 
	int32_t				myExecuteCount;


	double				myOffset;


};
