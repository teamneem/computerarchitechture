
/******************************************************************************
  Project #1
  Name: Neem Serra
  Section: 1
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
	Signal w, x, y, z, Valid, Present, Even, Prime;

	// Insert your Switches here
  
	Switch ( SD("1a"), w, 'w' );         // Switch w controlled by 'w' key
	Switch ( SD("2a"), x, 'x' );         // Switch x controlled by 'x' key
	Switch ( SD("3a"), y, 'y' );         // Switch y controlled by 'y' key
	Switch ( SD("4a"), z, 'z' );         // Switch z controlled by 'z' key

	circuits( SD("1b-4b"), w, x, y, z, Valid, Present, Even, Prime );

	// Insert your Probes here
	Probe ( (SD("1g"), "Valid"), Valid );      // Probe
	Probe ( (SD("2g"), "Present"), Present );  // Probe
	Probe ( (SD("3g"), "Even"), Even );        // Probe
	Probe ( (SD("4g"), "Prime"), Prime );      // Probe
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
	Signal Valid, Signal Present, Signal Even, Signal Prime )    
{
	Module( (sd, "circuits"), (w, x, y, z), (Valid, Present, Even, Prime) );

	// Insert your declarations for any auxiliary Signals here
	Signal notw, notx, noty, notz;
	Signal andV1, andV2, andP1, andP2, andPT1, andPT2, andPT3, andPT4;                 
	Signal orV;
	
	// Insert your circuit implementation here (Not, And, Or gates)
  
  	//Not gates
	Not ( SD("1b"), w, notw );
	Not ( SD("2b"), x, notx );
	Not ( SD("3b"), y, noty );
	Not ( SD("4b"), z, notz );
	//Not ( SD("4b"), z, Even );
 
	//AND gates
	And ( SD("1c"), (notx, noty), andV1 );                                     
	And ( SD("1c"), (notx, notz), andV2 );    
	
	And ( SD("4e"), (x, z, orV), andP1 );                                     
	And ( SD("4e"), (notx, y, notw, orV), andP2 );  
	
	And ( SD("3e"), (notz, orV), Even ); 	
	
	And ( SD("2e"), (x, noty, notz, orV), andPT1 );                                     
	And ( SD("2e"), (w, notx, orV), andPT2 );  
	And ( SD("2e"), (y, z, orV), andPT3 );  
 	And ( SD("2e"), (notx, z, orV), andPT4 ); 
 
 	//OR gates
	Or ( SD("2d"), (andV1, andV2, notw), orV );
	Or ( SD("1d"), (andV1, andV2, notw), Valid );
	Or ( SD("2f"), (andPT1, andPT2, andPT3, andPT4), Present );
	Or ( SD("4f"), (andP1, andP2), Prime );	
}

