 
#import <Foundation/Foundation.h>
#import "STPPicBookResourceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface STPPictureBookApi : NSObject

/**
 获取绘本资源列表
 @param resourceID  最后一条绘本ID，0表示获取首页（必选）
 @param count 每页返回的数量，可选范围1-50，建议值20 （必选）
 */
+ (void )getAllPicbookList:(NSInteger)resourceID count:(NSInteger)count block:(nullable void (^)(STPPicBookResourceList* _Nullable list,NSError * _Nullable error))block;

/**
 搜索绘本资源列表
 @param picBookName 绘本名称
 */
+ (void )searchPicbookList:(NSString *)picBookName block:(nullable void (^)(STPPicBookResourceList* _Nullable list,NSError * _Nullable error))block;

/// 获取绘本详情
/// @param picBookId 绘本ID
+ (void )getPicbookDetail:(NSString *)picBookId block:(nullable void (^)(STPPicBookDetailModel * _Nullable detailModel,NSError * _Nullable error))block;

/// 下载绘本或点读包
/// @param picBookId 需要传入资源的 mid参数
+ (void )addBookDownloadToDevice:(NSString *)picBookId block:(nullable void (^)(BOOL isSuss,NSError * _Nullable error))block;

/// 删除绘本（单本、批量：批量每次最多删除10个数据）
/// @param aIDs 绘本ID
+ (void )deleteDeviceBooks:(NSArray *)aIDs block:(nullable void (^)(BOOL isSuss,NSError * _Nullable error))block;

/**
 获取设备已添加绘本列表
 @param resourceID  最后一条绘本ID，0表示获取首页（必选）
 @param count 每页返回的数量，可选范围1-50，建议值20 （必选）
 */
+ (void )getLocalPicbookList:(NSInteger)resourceID count:(NSInteger)count block:(nullable void (^)(STPPicBookDetailList* _Nullable list,NSError * _Nullable error))block;

/// 获取设备端存储卡容量信息
+ (void )getSdcardInfo:(nullable void (^)(STPSdcardInfo * _Nullable cardInfo,NSError * _Nullable error))block;

/**
 获取已添加到设备上的点读包列表
 @param resourceID  最后一条点读包ID，0表示获取首页（必选）
 @param count 每页返回的数量，可选范围1-50，建议值20 （必选）
 */
+ (void )getLocalPackageList:(NSInteger)resourceID count:(NSInteger)count block:(nullable void (^)(STPPicBookDetailList* _Nullable list,NSError * _Nullable error))block;

/**
 获取全部可用的点读包列表
 @param resourceID  最后一条绘本ID，0表示获取首页（必选）
 @param count 每页返回的数量，可选范围1-50，建议值20 （必选）
 */
+ (void )getAllPackageListResourceId:(NSInteger)resourceID count:(NSInteger)count block:(nullable void (^)(STPPicBookResourceList* _Nullable list,NSError * _Nullable error))block;

@end

NS_ASSUME_NONNULL_END
