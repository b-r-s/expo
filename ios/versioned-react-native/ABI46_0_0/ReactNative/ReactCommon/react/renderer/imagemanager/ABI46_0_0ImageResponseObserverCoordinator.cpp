/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "ABI46_0_0ImageResponseObserverCoordinator.h"

#include <algorithm>

#include <ABI46_0_0React/ABI46_0_0debug/ABI46_0_0React_native_assert.h>

namespace ABI46_0_0facebook {
namespace ABI46_0_0React {

void ImageResponseObserverCoordinator::addObserver(
    ImageResponseObserver const &observer) const {
  mutex_.lock();
  switch (status_) {
    case ImageResponse::Status::Loading: {
      observers_.push_back(&observer);
      mutex_.unlock();
      break;
    }
    case ImageResponse::Status::Completed: {
      auto imageData = imageData_;
      auto imageMetadata = imageMetadata_;
      mutex_.unlock();
      observer.didReceiveImage(ImageResponse{imageData, imageMetadata});
      break;
    }
    case ImageResponse::Status::Failed: {
      mutex_.unlock();
      observer.didReceiveFailure();
      break;
    }
  }
}

void ImageResponseObserverCoordinator::removeObserver(
    ImageResponseObserver const &observer) const {
  std::lock_guard<std::mutex> lock(mutex_);

  // We remove only one element to maintain a balance between add/remove calls.
  auto position = std::find(observers_.begin(), observers_.end(), &observer);
  if (position != observers_.end()) {
    observers_.erase(position, observers_.end());
  }
}

void ImageResponseObserverCoordinator::nativeImageResponseProgress(
    float progress) const {
  mutex_.lock();
  auto observers = observers_;
  ABI46_0_0React_native_assert(status_ == ImageResponse::Status::Loading);
  mutex_.unlock();

  for (auto observer : observers) {
    observer->didReceiveProgress(progress);
  }
}

void ImageResponseObserverCoordinator::nativeImageResponseComplete(
    ImageResponse const &imageResponse) const {
  mutex_.lock();
  imageData_ = imageResponse.getImage();
  imageMetadata_ = imageResponse.getMetadata();
  ABI46_0_0React_native_assert(status_ == ImageResponse::Status::Loading);
  status_ = ImageResponse::Status::Completed;
  auto observers = observers_;
  mutex_.unlock();

  for (auto observer : observers_) {
    observer->didReceiveImage(imageResponse);
  }
}

void ImageResponseObserverCoordinator::nativeImageResponseFailed() const {
  mutex_.lock();
  ABI46_0_0React_native_assert(status_ == ImageResponse::Status::Loading);
  status_ = ImageResponse::Status::Failed;
  auto observers = observers_;
  mutex_.unlock();

  for (auto observer : observers) {
    observer->didReceiveFailure();
  }
}

} // namespace ABI46_0_0React
} // namespace ABI46_0_0facebook
