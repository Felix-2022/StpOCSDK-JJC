#
# Be sure to run `pod lib lint StpOCSDK-JJC.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'StpOCSDK-JJC'
  s.version          = '0.1.1'
  s.summary          = 'A short description of StpOCSDK-JJC.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/Felix-2022/StpOCSDK-JJC'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Felix' => '252141465@qq.com' }
  s.source           = { :git => 'https://github.com/Felix-2022/StpOCSDK-JJC.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  s.requires_arc = true
  s.libraries = 'c++'
  s.frameworks = 'UIKit','WebKit','CoreTelephony','SystemConfiguration','MobileCoreServices','AVFoundation'
  s.dependency 'AFNetworking','4.0.1'
  s.dependency 'YYModel'
 #依赖自己的或别人的Framework文件
  s.vendored_frameworks = 'SpeakPen.framework'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC'}
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
