//
//  Copyright (c) 2012, Infinite Droplets V.O.F.
//  All rights reserved.
//  
//  Starry was released under the BSD Licence
//

#import <sqlite3.h>


@interface SRSQLiteDelegate : NSObject {
	NSString *databasePath;
}
-(void) readStarsFromDatabase;
-(void) checkAndCreateDatabase;
@end
