#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Header/Date.h"
#include "Header/Severe.h"
#include "Header/Syntax.h"


bool SVR(int wind, double hail, bool tornado) {
    if ((wind < 58) && (hail < 1.00)) {
        printf("Failed to meet the criteria of issuing a Severe Thunderstorm Warning.\n");
        return false;
    }
    
    char* hailType;
    if (wind >= 58) {
        if (hail == 0.75) hailType = "penny size";
        else if (hail == 0.88) hailType = "nickel size";
        else if (hail == 1.00) hailType = "quarter size";
        else if (hail == 1.25) hailType = "half dollar size";
        else if (hail == 1.50) hailType = "ping pong ball size";
        else if (hail == 1.75) hailType = "golf ball size";
        else if (hail == 2.00) hailType = "two inch";
        else if (hail == 2.50) hailType = "tennis ball size";
        else if (hail == 2.75) hailType = "baseball size";

    }
    else {
        if (hail == 0.75) hailType = "Penny size";
        else if (hail == 0.88) hailType = "Nickel size";
        else if (hail == 1.00) hailType = "Quarter size";
        else if (hail == 1.25) hailType = "Half dollar size";
        else if (hail == 1.50) hailType = "Ping pong ball size";
        else if (hail == 1.75) hailType = "Golf ball size";
        else if (hail == 2.00) hailType = "Two inch";
        else if (hail == 2.50) hailType = "Tennis ball size";
        else if (hail == 2.75) hailType = "Baseball size";

    }

    if (wind >= 80 || hail >= 2.00) printf("BULLETIN - EAS ACTIVATION REQUESTED\n");
    else printf("BULLETIN - IMMEDIATE BROADCAST REQUESTED\n");

    printf("Severe Thunderstorm Warning\nNational Weather Service Boston/Norton MA\n");
    printCurrentDateAndTime();
    printf("The National Weather Service in Boston/Norton MA has issued a\n\n");
    printf("* Severe Thunderstorm Warning for...\n  Essex County in northeastern Massachusetts...\n  North central Norfolk County in eastern Massachusetts...\n  Suffolk County in eastern Massachusetts...\n  Middlesex County in northeastern Massachusetts...\n  Northern Plymouth County in southeastern Massachusetts...\n\n");
    printf("* Until 345 PM EDT.\n\n");
    printf("* At 252 PM EDT, severe thunderstorms were located along a line\n  extending from Pepperell to Carlisle to Sherborn, moving northeast\n  at 40 mph.\n\n");

    if (wind >= 80 || hail >= 2.75) printf("  THIS IS A VERY DESTRUCTIVE STORM\n\n");

    if (wind < 58) printf("  HAZARD...%s hail.\n\n", hailType);
    else if (hail < 0.75) printf("  HAZARD...%d mph wind gusts.\n\n", wind);
    else printf("  HAZARD...%d mph wind gusts and %s hail.\n\n", wind, hailType);

    printf("  SOURCE...Radar indicated.\n\n");

    char* impactType;
    if (wind <= 58 && hail == 1.00) impactType = "  IMPACT...Minor hail damage to vehicles is possible.\n\n";
    else if (wind == 60 && hail <= 0.75) impactType = "  IMPACT...Expect damage to trees and power lines.\n\n";
    else if ((wind == 60 && hail == 1.00) || (wind == 60 && hail == 1.25)) impactType = "  IMPACT...Hail damage to vehicles is expected. Expect wind damage\n           to roofs, siding, and trees.\n\n";
    else impactType = "IMPACT...People and animals outdoors will be injured. Expect hail damage to roofs, siding, windows, and vehicles. Expect wind damage to roofs, siding, and trees.";

    printf("%s", impactType);
    printf("PRECAUTIONARY/PREPARDNESS ACTIONS...\n\n");
    printf("For your protection move to an interior room on the lowest floor of a\nbuilding.\n\n");
    printf("Torrential rainfall is occurring with these storms, and may lead to\nflash flooding. Do not drive your vehicle through flooded roadways.\n\n");
    printf("&&\n\n");
    printf("LAT...LON 4287 7082 4283 7081 4281 7087 4280 7079\n      4270 7073 4271 7061 4264 7056 4239 7094\n      ");
    printf("4231 7079 4221 7142 4248 7142 4264 7167\n      4271 7158 4270 7129 4274 7124 4274 7118\n      ");
    printf("4282 7115 4281 7107 4286 7103 4289 7092\nTIME...MOT...LOC 1852Z 217DEG 34KT 4266 7162 4254 7134 4224 7137");
    printf("\n\n");

    if (tornado) printf("TORNADO...POSSIBLE\n");

    if ((wind >= 70 && wind < 80) || (hail >= 1.75 && hail < 2.75)) printf("THUNDERSTORM DAMAGE THREAT...CONSIDERABLE\n");
    else if (wind >= 80 || hail >= 2.75) printf("THUNDERSTORM DAMAGE THREAT...DESTRUCTIVE\n");

    if (hail < 0.75) printf("HAIL THREAT...RADAR INDICATED\nMAX HAIL SIZE...<.75\nWIND THREAT...RADAR INDICATED\n");
    else printf("HAIL THREAT...RADAR INDICATED\nMAX HAIL SIZE...%.2f IN\nWIND THREAT...RADAR INDICATED\n", hail);
    
    if (wind < 50) printf("MAX WIND GUST...<50 MPH\n\n$$\n\nBL");
    else printf("MAX WIND GUST...%d MPH\n\n$$\n\nBL\n", wind);
    return true;
}

void TOR(void) {
    char* MESSAGE = (char*)malloc(sizeof(char) * 100);
    if (MESSAGE == NULL) {
        errorMessage(2);
    }

    char string[] = "BULLETIN - EAS ACTIVATION REQUESTED\nTornado Warning\nNational Weather Service\n";
    strcpy(MESSAGE, string);
    printf("%s\n", MESSAGE);

    free(MESSAGE);
}