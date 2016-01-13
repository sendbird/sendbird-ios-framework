Pod::Spec.new do |s|
  s.name         = "SendBirdSDK"
  s.version      = "2.0.3"
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

  s.public_header_files = 'SendBirdSDK.framework/Headers/SendBirdSDK.h', 'SendBirdSDK.framework/Headers/SendBird.h', 'SendBirdSDK.framework/Headers/SendBirdAPIClient.h', 'SendBirdSDK.framework/Headers/SendBirdBroadcastMessage.h', 'SendBirdSDK.framework/Headers/SendBirdChannel.h', 'SendBirdSDK.framework/Headers/SendBirdChannelListQuery.h', 'SendBirdSDK.framework/Headers/SendBirdClient.h', 'SendBirdSDK.framework/Headers/SendBirdCommand.h', 'SendBirdSDK.framework/Headers/SendBirdError.h', 'SendBirdSDK.framework/Headers/SendBirdFileInfo.h', 'SendBirdSDK.framework/Headers/SendBirdFileLink.h', 'SendBirdSDK.framework/Headers/SendBirdMember.h', 'SendBirdSDK.framework/Headers/SendBirdMemberInMessagingChannel.h', 'SendBirdSDK.framework/Headers/SendBirdMemberListQuery.h', 'SendBirdSDK.framework/Headers/SendBirdMention.h', 'SendBirdSDK.framework/Headers/SendBirdMessage.h', 'SendBirdSDK.framework/Headers/SendBirdMessageListQuery.h', 'SendBirdSDK.framework/Headers/SendBirdMessageModel.h', 'SendBirdSDK.framework/Headers/SendBirdMessagingChannel.h', 'SendBirdSDK.framework/Headers/SendBirdMessagingChannelListQuery.h', 'SendBirdSDK.framework/Headers/SendBirdMessagingUnreadCountQuery.h', 'SendBirdSDK.framework/Headers/SendBirdReadStatus.h', 'SendBirdSDK.framework/Headers/SendBirdSender.h', 'SendBirdSDK.framework/Headers/SendBirdSystemMessage.h', 'SendBirdSDK.framework/Headers/SendBirdTypeStatus.h', 'SendBirdSDK.framework/Headers/SendBirdUser.h', 'SendBirdSDK.framework/Headers/SendBirdWSClient.h', 'SendBirdSDK.framework/Headers/SendBirdUser.h', 'SendBirdSDK.framework/Headers/SendBirdSRWebSocket.h'
end
