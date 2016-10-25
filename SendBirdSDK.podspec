Pod::Spec.new do |s|
  s.name         = "SendBirdSDK"
  s.version      = "2.2.26"
  s.summary      = "SendBird iOS Framework"
  s.description  = "Messaging and Chat API for Mobile Apps and Websites"
  s.homepage     = "https://sendbird.com"
  s.license      = "Commercial"
  s.author       = { "Jed Gyeong" => "jed.gyeong@sendbird.com" }
  s.source       = { :git => "https://github.com/smilefam/sendbird-ios-framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "7.0"
  s.ios.vendored_frameworks = 'SendBirdSDK.framework'
  s.ios.frameworks = ["UIKit", "QuartzCore", "CFNetwork", "Security", "Foundation", "MobileCoreServices"]
  s.ios.library   = "icucore"
end
