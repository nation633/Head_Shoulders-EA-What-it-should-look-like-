// Define constants
const int HSP = 100;        // Size of the Head and Shoulders pattern (in pips)
const double TP = 100.0;    // Take profit level (in pips)
const double SL = 50.0;     // Stop loss level (in pips)

// Define global variables
double Shoulder = 0.0;  // Highest point of the left or right shoulder
double Head = 0.0;       // Lowest point of the head
double Neckline = 0.0;      // Level of the neckline

// Define trading signals
bool BuySignal = false;
bool SellSignal = false;

// Define initialization function
int OnInit()
{
    // Define the size of the Head and Shoulders pattern
    HSP = HSP * SymbolInfoDouble(_Symbol, SYMBOL_TRADE_TICK_SIZE);

    return(INIT_SUCCEEDED);
}

// Define function to check for a Head and Shoulders pattern
bool CheckHSPattern()
{
    bool HSPattern = false;

    for(int i=HSP+2; i>=0; i--)
    {
        // Check for left shoulder
        if(iHigh(NULL, 0, i) > iHigh(NULL, 0, i+1) && iHigh(NULL, 0, i) > iHigh(NULL, 0, i-1))
        {
            Shoulder = iHigh(NULL, 0, i);
            // Check for head
            if(iLow(NULL, 0, i+HSP) < iLow(NULL, 0, i+HSP+1))
            {
                Head = iLow(NULL, 0, i+HSP);
                // Check for right shoulder
                if(iHigh(NULL, 0, i+2*HSP) > iHigh(NULL, 0, i+2*HSP+1) && iHigh(NULL, 0, i+2*HSP) > iHigh(NULL, 
