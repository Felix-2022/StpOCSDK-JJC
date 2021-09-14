# StpOCSDK
SDK 以 pod 引入方式 获取。pod = ' StpOCSDK '  SDK 包括：


## 概述
本 SDK 主要提供了百进智能点读笔常用的五大模块接口

+ 账号管理
  1. 登录
  2. 登出
  3. 设置操作设备
  4. 当前操作设备ID
  
+ 设备管理
  1. 获取设备列表
  2. 获取设备详情
  3. 获取设备硬件信息
  4. 修改设备音量
  5. 修改设备名称
  6. 解除设备绑定
  7. 上传设备日志
  
+ 学习报告
  1. 已读绘本列表(按日期查询、倒叙分页查询)
  2. 各项学习数据(点读、跟读、日报）(按日期查询、倒叙分页查询)
  3. 各项报告趋势(点读、跟读、学习时长、阅读绘本数)
  
+ 绘本管理
  1. 全部绘本
  2. 搜索绘本
  3. 设备已添加绘本
  4. 绘本详情
  5. 下载绘本或点读包
  6. 删除绘本(单本、批量)
  7. 获取设备存储空间状态
  8. 全部点读包
  9. 已下载点读包
  
+ 同步课堂
  1. 设置个推ID
  2. 同步课堂开关
  3. 同步课堂心跳


设备相关API

```ruby
@interface STPDeviceApi 
```
用户账户相关API

```ruby
@interface STPAuthApi
@interface STPUserApi

```
绘本相关API

```ruby
@interface STPPictureBookApi
```

学习报告相关API

```ruby
@interface STPStudyReportApi
```

## Installation

安装方式

```ruby
pod 'StpOCSDK'
```

## 相关流程

### Config配置

在调用SDK相关API之前，需要先配置

```ruby
@interface STPAccessConfig

设置开发环境
STPAccessConfiger.developEnv = Env_Development;
[STPAccessConfiger setPackageId:@"输入分配给您的PackageId"];

```

### 登录流程
#### 用户选择登录方式，包括 普通用户登录 和 第三方登录的方式。

. 普通用户登录

```ruby

 @param phoneNum 手机号码
 @param passWord 用户密码
 @param pushToken 推送token
+ (void)login:(NSString*_Nonnull)phoneNum passWord:(NSString*_Nonnull)passWord pushToken:(NSString*)token completionBlock:(nullable void (^)(STPUserModel *user,NSError *error)) completionBlock;
```

. 第三方登录


```ruby

/**
 第三方登录

 @param phone 手机号码
 @param passwd 用户密码
 @param thirdCode 第三方code
 */
+(void)loginEx:(NSString*)phone passwd:(NSString*)passwd thirdCode:(NSString*)thirdCode block:(void (^)(STPUserModel *user,NSError *error))block;
```

. 设置当前操作的设备ID与设备AppId

```ruby
/**
设置操作点读笔

@param currDeviceID 点读笔设备ID
@param appId 点读笔AppId
*/
-(void)setCurrDeviceID:(NSString * _Nonnull)currDeviceID  appId:(NSString *_Nonnull) appId;

```
### 配网流程

. 首先连接硬件蓝牙，然后将wifi名称和密码信息（包括wifi密码和用户ID）发送到硬件设备端。发送之后硬件会提示：正在配网中。 此时APP端定时轮询获取配网的结果。

/**
 获取配网的结果  建议采用定时轮询
 */
 
```ruby
+(void)getDeviceBindInfo:(void (^)(STPBindInfo* _Nullable response, NSError *_Nullable error))block;
```


/**
 上传日志 (保持当前连接设备联网)
 */

```ruby
+ (void)uploadLogToDeviceBlock:(nullable void (^)(BOOL isSuss,NSError* _Nullable error))block;
```

. 蓝牙配网Demo

```ruby
参见blueTooth Demo
https://github.com/Felix-2022/StpDemo
```

### 绘本管理流程

```ruby
@interface STPPictureBookApi
```
```ruby
/**
 获取全部绘本资源列表
 @param resourceID  最后一条绘本ID，0表示获取首页（必选）
 @param count 每页返回的数量，可选范围1-50，建议值20 （必选）
 */
+ (void )getAllPicbookList:(NSInteger)resourceID count:(NSInteger)count block:(nullable void (^)(STPPicBookResourceList* _Nullable list,NSError * _Nullable error))block;

返回数据封装成  STPPicBookResourceList {
@property(nonatomic,assign) NSInteger total;// 分类的总数量
@property(nonatomic,strong) NSArray<STPPicBookResourceModel*> *lists;// 资源分类列表
}

其中 STPPicBookResourceModel 表示 绘本资源（添加到设备之前）{
@property(nonatomic,assign) NSInteger rID;//资源ID
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) NSString *cover;
@property(nonatomic,strong) NSString *author;
@property(nonatomic,strong) NSString *mid;// 点读包id
@property(nonatomic,assign) NSInteger size;
@property(nonatomic,assign) NSInteger status;// 添加状态 0未添加 1已添加
@property(nonatomic,assign) NSInteger downloadable;//是否可以下载 0否 1是
@property(nonatomic,assign) NSInteger createdAt;//
@property(nonatomic,assign) NSInteger updatedAt;//
}

```
```ruby
/**
 搜索绘本资源列表
 @param picBookName 绘本名称
 */
+ (void )searchPicbookList:(NSString *)picBookName block:(nullable void (^)(STPPicBookResourceList* _Nullable list,NSError * _Nullable error))block;

```

```ruby

/// 获取绘本详情
/// @param picBookId 绘本ID
+ (void )getPicbookDetail:(NSString *)picBookId block:(nullable void (^)(STPPicBookDetailModel * _Nullable detailModel,NSError * _Nullable error))block;

返回数据 STPPicBookDetailModel (绘本或点读包详情 , 已经添加到设备){
@property(nonatomic,assign) NSInteger rID; //资源ID
@property(nonatomic,strong) NSString *name;
@property(nonatomic,strong) NSString *cover;
@property(nonatomic,strong) NSString *author;
@property(nonatomic,strong) NSString *readGuideHtml;
@property(nonatomic,strong) NSString *mid; // 点读包id
@property(nonatomic,assign) NSInteger size; //书籍大小 字节
@property(nonatomic,assign) NSInteger status; //下载状态 0等待下载 1下载中 2下载完成 3下载失败
@property(nonatomic,assign) NSInteger progress; // 下载进度 0-100
@property(nonatomic,assign) NSInteger createdAt;
@property(nonatomic,assign) NSInteger updatedAt;
}


```

```ruby
/// 下载绘本或点读包
/// @param picBookId 绘本ID
+ (void )addBookDownloadToDevice:(NSString *)picBookId block:(nullable void (^)(BOOL isSuss,NSError * _Nullable error))block;

```

```ruby

/// 删除绘本（单本、批量：批量每次最多删除10个数据）
/// @param aIDs 绘本ID
+ (void )deleteDeviceBooks:(NSArray *)aIDs block:(nullable void (^)(BOOL isSuss,NSError * _Nullable error))block;
```
```ruby
/**
 获取设备已添加绘本列表
 @param resourceID  最后一条绘本ID，0表示获取首页（必选）
 @param count 每页返回的数量，可选范围1-50，建议值20 （必选）
 */
+ (void )getLocalPicbookList:(NSInteger)resourceID count:(NSInteger)count block:(nullable void (^)(STPPicBookDetailList* _Nullable list,NSError * _Nullable error))block;
```
```ruby
/// 获取设备端存储卡容量信息
+ (void )getSdcardInfo:(nullable void (^)(STPSdcardInfo * _Nullable cardInfo,NSError * _Nullable error))block;
```
```ruby
/**
 获取已添加到设备上的点读包列表
 @param resourceID  最后一条点读包ID，0表示获取首页（必选）
 @param count 每页返回的数量，可选范围1-50，建议值20 （必选）
 */
+ (void )getLocalPackageList:(NSInteger)resourceID count:(NSInteger)count block:(nullable void (^)(STPPicBookDetailList* _Nullable list,NSError * _Nullable error))block;
```
```ruby
/**
 获取全部可用的点读包列表
 @param resourceID  最后一条绘本ID，0表示获取首页（必选）
 @param count 每页返回的数量，可选范围1-50，建议值20 （必选）
 */
+ (void )getAllPackageListResourceId:(NSInteger)resourceID count:(NSInteger)count block:(nullable void (^)(STPPicBookResourceList* _Nullable list,NSError * _Nullable error))block;

```

### 学习报告管理流程

```ruby
@interface STPStudyReportApi

```
```ruby
/// 各项学习数据 (根据时间)
/// @param type 候选值对应的字符串(获取跟读数据 传 @"follow-reading")
/// 1: 点读数量(point-reading)
/// 2：绘本阅读量 (pic-book)
/// 3：学习时长(duration)
/// 4：跟读次数 (follow-reading)
/// @param start 起始日期 格式 YYYY-MM-DD（当天的话 start、end 都传同一个值）
/// @param end 终止日期
+ (void )getStudyAchieveData:(NSString *)type
                   startDate:(NSString *)start
                     endDate:(NSString *)end
                       block:(nullable void (^)(STPFollowReadResultModel* _Nullable detailModel,NSError * _Nullable error))block;

```
```ruby

/// 各项学习数据 (根据顺序)
/// @param type 候选值对应的字符串(获取跟读数据 传 @"follow-reading")
/// 1: 点读数量(point-reading)
/// 2：绘本阅读量 (pic-book)
/// 3：学习时长(duration)
/// 4：跟读次数 (follow-reading)
/// @param fromId 数据起始ID ，0表示最新的数据
/// @param count 数量
/// @param block block
+ (void)getStudyAchieveData:(NSString *)type fromId:(NSInteger)fromId count:(NSInteger)count block:(void (^)(STPFollowReadResultModel * _Nullable detailModel, NSError * _Nullable error))block;

```
```ruby
/// 获取已读绘本列表(根据时间)
/// @param start 起始日期 格式 YYYY-MM-DD （当天的话 start、end 都传同一个值）
/// @param end 终止日期
/// @param block block
+ (void)getTodayReadBookListStartDate:(NSString *)start
                              endDate:(NSString *)end
                                block:(nullable void(^)(STPFollowReadResultModel *_Nullable detailModel,NSError* _Nullable error))block;

/// 获取已读绘本列表(根据顺序)
/// @param fromId 数据起始ID ，0表示最新的数据
/// @param count 数量
/// @param block block
+ (void)getTodayReadBookListFromId:(NSInteger)fromId
                             count:(NSInteger)count
                             block:(nullable void(^)(STPFollowReadResultModel *_Nullable detailModel,NSError* _Nullable error))block;

```
```ruby

/// 获取各项报告趋势详情
/// @param type (数据类型 例如：获取点读次数 传@"point-reading")
/// 1: 点读数量(point-reading)
/// 2：学习时长(duration)
/// @param start 起始日期 格式 YYYY-MM-DD （当天的话 start、end 都传同一个值）
/// @param end 终止日期
/// @param block block
+ (void)getPassdayTrendListWithType:(NSString *)type
                          StartDate:(NSString *)start
                            endDate:(NSString *)end
                              andCallback:(nullable void(^)(STPTrendListModel *_Nullable detailModel,NSError* _Nullable error))block;
                              
```
### 同步课堂流程

```ruby
/// 同步课堂开关
/// @param enable YES开 NO关
+ (void)handleSyncSwitch:(BOOL)enable
                   block:(nullable void (^)(BOOL isSuss,NSError* _Nullable error))block;
                   
```
```ruby
/// 同步课堂心跳
+ (void)sendSyncHeartbeatWithBlock:(nullable void (^)(BOOL isSuss,NSError* _Nullable error))block;
+ 
```

### 全部SDK接口使用Demo
https://github.com/Felix-2022/StpOCSDK/blob/master/Example/StpOCSDK/STPViewController.m

