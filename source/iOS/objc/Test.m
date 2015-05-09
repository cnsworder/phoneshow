#import <Foundation/NSString.h>
#import <Foundation/Foundation.h>

@interface NSString (EXStr)
-(void) pd;
@end

@implementation NSString (EXStr)
-(void) pd {
   NSLog(@"PD");
}
@end

@protocol MyDelegate <NSObject>
-(void) my;
@end

@interface OhMy: NSObject<MyDelegate>
-(void) my;
@end

@implementation OhMy
-(void) my {
    NSLog(@"my");
}
@end

@interface Test : NSObject
{
    int a;
    id<MyDelegate> delegate;
}

@property int a;

-(void) tprint:(NSString *)name andId:(int) id;

@end

@implementation Test

@synthesize a;

-(id) init {

    [super init];
}

-(void) dealloc {
    [super dealloc];
}

-(void) tprint:(NSString *)name andId:(int) id {
    [name pd];
    NSLog(@"%d:%@", id, name);
}

-(void) delegateDo:(id<MyDelegate>)my {
    delegate = my;
    [delegate my];
}

@end


int main()
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    //@autoreleasepool {
        Test *test = [[Test alloc] init];
        test.a = 15;
        [test tprint:@"cnsworder" andId:test.a];
        OhMy *oh = [[OhMy alloc] init];
        [test delegateDo:oh];
        [test dealloc];
        //    ^() {
        //      NSLog(@"block");  
        //    }();
        NSLog(@"aa");
    //}
    [pool release];
//    [pool drain];
}
