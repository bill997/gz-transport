/*
 * Copyright (C) 2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include "ignition/transport/SubscribeOptions.hh"
#include "ignition/transport/test_config.h"
#include "gtest/gtest.h"

using namespace ignition;

//////////////////////////////////////////////////
/// \brief Check the copy constructor.
TEST(SubscribeOptionsTest, copyConstructor)
{
  transport::SubscribeOptions opts1;
  opts1.SetMsgsPerSec(2u);
  EXPECT_EQ(opts1.MsgsPerSec(), 2u);
  transport::SubscribeOptions opts2(opts1);
  EXPECT_EQ(opts2.MsgsPerSec(), opts1.MsgsPerSec());
}

//////////////////////////////////////////////////
/// \brief Check the accessors.
TEST(SubscribeOptionsTest, accessors)
{
  // MsgsPerSec.
  transport::SubscribeOptions opts;
  EXPECT_EQ(opts.MsgsPerSec(), transport::SubscribeOptions::kUnthrottled);
  opts.SetMsgsPerSec(3u);
  EXPECT_EQ(opts.MsgsPerSec(), 3u);
}

//////////////////////////////////////////////////
/// \brief Check Throttled().
TEST(SubscribeOptionsTest, throttled)
{
  transport::SubscribeOptions opts;
  EXPECT_FALSE(opts.Throttled());
  opts.SetMsgsPerSec(3u);
  EXPECT_TRUE(opts.Throttled());
}

//////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
