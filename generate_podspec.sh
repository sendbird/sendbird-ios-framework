#!/bin/bash

VERSION=''

while getopts v: flag
do
    case "${flag}" in
        v) VERSION=${OPTARG};;
        *) error "Unexpected option ${flag}";;
    esac
done

echo $VERSION

if [ -z $VERSION ]; then
    echo 'Version is required'
fi

TEMPLATE="
Pod::Spec.new do |s|
  s.name         = 'SendBirdSDK'
  s.version      = \"$VERSION\"
  s.summary      = 'Sendbird Chat iOS Framework'
  s.description  = 'Messaging and Chat API for Mobile Apps and Websites'
  s.homepage     = 'https://sendbird.com'
  s.license      = 'Commercial'
  s.authors      = {
    'Jed Gyeong' => 'jed.gyeong@sendbird.com',
    'Celine Moon' => 'celine.moon@sendbird.com',
    'Ernest Hong' => 'ernest.hong@sendbird.com'
    'Damon Park' => 'damon.park@sendbird.com'
  }
  s.source       = { :git => 'https://github.com/sendbird/sendbird-ios-framework.git', :tag => \"v$VERSION\" }
  s.requires_arc = true
  s.platform = :ios, '11.0'
  s.documentation_url = 'https://docs.sendbird.com/'
  s.ios.vendored_frameworks = 'Sources/SendBirdSDK.xcframework'
  s.ios.frameworks = ['UIKit', 'CFNetwork', 'Security', 'Foundation', 'MobileCoreServices', 'SystemConfiguration', 'CoreFoundation']
  s.ios.library   = 'icucore'
end
"

echo -e "$TEMPLATE" > SendBirdSDK.podspec
