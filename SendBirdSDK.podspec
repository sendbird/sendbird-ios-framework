Pod::Spec.new do |s|
  s.name         = "SendBirdSDK"
  s.version      = "2.0.14"
  s.summary      = "SendBird iOS Framework"
  s.description  = <<-DESC
                   SendBird is the simplest solution for chat and messaging.
                   DESC
  s.homepage     = "https://sendbird.com"
  s.license      = "Commercial"
  s.author       = { "Jed Gyeong" => "jed.gyeong@sendbird.com" }
  s.source       = { :git => "https://github.com/smilefam/sendbird-ios-framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true

  s.platform     = :ios, "6.0"
  s.ios.platform = :ios, "6.0"
  s.ios.vendored_frameworks = 'SendBirdSDK.framework'
  s.ios.frameworks = ["AdSupport", "UIKit", "QuartzCore", "CFNetwork", "Security", "Foundation", "MobileCoreServices"]
  s.ios.library   = "icucore"
end
