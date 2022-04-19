
Pod::Spec.new do |s|
  s.name         = 'SendBirdSDK'
  s.version      = "3.1.13"
  s.summary      = 'Sendbird Chat iOS Framework'
  s.description  = 'Messaging and Chat API for Mobile Apps and Websites'
  s.homepage     = 'https://sendbird.com'
  s.license      = 'Commercial'
  s.authors      = {
    'Jed Gyeong' => 'jed.gyeong@sendbird.com',
    'Celine Moon' => 'celine.moon@sendbird.com',
    'Erenst Hong' => 'ernest.hong@sendbird.com'
  }
  s.source       = { :git => 'https://github.com/sendbird/sendbird-ios-framework.git', :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, '9.0'
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'Sources/SendBirdSDK.xcframework'
  s.ios.frameworks = ['UIKit', 'CFNetwork', 'Security', 'Foundation', 'Network', 'MobileCoreServices', 'SystemConfiguration', 'CoreFoundation']
  s.ios.library   = 'icucore'
end

