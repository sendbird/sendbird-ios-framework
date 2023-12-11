
Pod::Spec.new do |s|
  s.name         = 'SendBirdSDK'
  s.version      = "3.1.55"
  s.summary      = 'Sendbird Chat iOS Framework'
  s.description  = 'Messaging and Chat API for Mobile Apps and Websites'
  s.homepage     = 'https://sendbird.com'
  s.license      = 'Commercial'
  s.authors      = {
    'Jed Gyeong' => 'jed.gyeong@sendbird.com',
    'Celine Moon' => 'celine.moon@sendbird.com',
    'Damon Park' => 'damon.park@sendbird.com',
    'Tez Park' => 'tez.park@sendbird.com',
    'Young Hwang' => 'young.hwang@sendbird.com',
    'Minhyuk Kim' => 'minhyuk.kim@sendbird.com'
  }
  s.source       = { :git => 'https://github.com/sendbird/sendbird-ios-framework.git', :tag => "v3.1.55" }
  s.requires_arc = true
  s.platform = :ios, '11.0'
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'Sources/SendBirdSDK.xcframework'
  s.ios.frameworks = ['UIKit', 'CFNetwork', 'Security', 'Foundation', 'MobileCoreServices', 'SystemConfiguration', 'CoreFoundation']
  s.ios.library   = 'icucore'
end

