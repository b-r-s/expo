/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

package abi45_0_0.host.exp.exponent.modules.api.components.slider;

import abi45_0_0.com.facebook.react.bridge.Arguments;
import abi45_0_0.com.facebook.react.bridge.WritableMap;
import abi45_0_0.com.facebook.react.uimanager.events.Event;
import abi45_0_0.com.facebook.react.uimanager.events.RCTEventEmitter;

/**
 * Event emitted by a ReactSliderManager when user changes slider position.
 */
public class ReactSliderEvent extends Event<ReactSliderEvent> {

  public static final String EVENT_NAME = "topChange";

  private final double mValue;
  private final boolean mFromUser;

  public ReactSliderEvent(int viewId, double value, boolean fromUser) {
    super(viewId);
    mValue = value;
    mFromUser = fromUser;
  }

  public double getValue() {
    return mValue;
  }

  public boolean isFromUser() {
    return mFromUser;
  }


  @Override
  public String getEventName() {
    return EVENT_NAME;
  }

  @Override
  public short getCoalescingKey() {
    return 0;
  }
  @Override
  public void dispatch(RCTEventEmitter rctEventEmitter) {
    rctEventEmitter.receiveEvent(getViewTag(), getEventName(), serializeEventData());
  }

  private WritableMap serializeEventData() {
    WritableMap eventData = Arguments.createMap();
    eventData.putInt("target", getViewTag());
    eventData.putDouble("value", getValue());
    eventData.putBoolean("fromUser", isFromUser());
    return eventData;
  }
}
