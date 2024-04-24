Pod::Spec.new do |s|
  s.name         = "SendBirdSDK"
  s.version      = "3.0.238-privacy"
  s.summary      = "SendBird iOS Framework"
  s.description  = "Messaging and Chat API for Mobile Apps and Websites"
  s.homepage     = "https://sendbird.com"
  s.license      = "Commercial"
  s.authors      = { 
	  "Jed Gyeong" => "jed.gyeong@sendbird.com", 
	  "Woo" => "wooyoung.chung@sendbird.com", 
      "Celine Moon" => "celine.moon@sendbird.com",
      "Minhyuk Kim" => "minhyuk.kim@sendbird.com"
  }
  s.source       = { :git => "https://github.com/sendbird/sendbird-ios-framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "12.0"
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'Sources/SendBirdSDK.xcframework'
  s.ios.frameworks = ["UIKit", "CFNetwork", "Security", "Foundation", "Network", "MobileCoreServices", "SystemConfiguration", "CoreFoundation"]
  s.ios.library   = "icucore"
end
