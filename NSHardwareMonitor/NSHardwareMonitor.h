//
//  NSHWMonitor.h
//  HWSensors
//
//  Created by Natan Zalkin on 23/02/12.
//  Copyright (c) 2012 natan.zalkin@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NSHardwareMonitorSensor.h"
#import "NSATASmartReporter.h"

@interface NSHardwareMonitor : NSObject
{
@private
    io_service_t service;
    NSATASmartReporter *smartReporter;
    NSMutableArray *sensors;
    NSMutableDictionary *keys;
}

@property (readonly) NSArray *sensors;

+ (NSHardwareMonitor*)hardwareMonitor;

+ (NSDictionary*)populateValues;
+ (NSData*)populateValueForKey:(NSString *)key;

- (NSHardwareMonitorSensor*)addSensorWithKey:(NSString*)key caption:(NSString*)caption group:(NSUInteger)group;
- (NSHardwareMonitorSensor*)addSMARTSensorWithGenericDisk:(NSATAGenericDisk*)disk group:(NSUInteger)group;

- (id)init;
- (void)dealloc;

- (void)rebuildSensorsList;
- (void)updateSMARTSensorsValues;
- (void)updateGenericSensorsValuesButOnlyFavorits:(BOOL)updateOnlyFavorites;

- (NSArray*)getAllSensorsInGroup:(NSUInteger)group;

@end