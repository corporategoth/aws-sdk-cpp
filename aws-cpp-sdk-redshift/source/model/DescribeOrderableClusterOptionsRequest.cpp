/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/redshift/model/DescribeOrderableClusterOptionsRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::Redshift::Model;
using namespace Aws::Utils;

DescribeOrderableClusterOptionsRequest::DescribeOrderableClusterOptionsRequest() : 
    m_clusterVersionHasBeenSet(false),
    m_nodeTypeHasBeenSet(false),
    m_maxRecords(0),
    m_maxRecordsHasBeenSet(false),
    m_markerHasBeenSet(false)
{
}

Aws::String DescribeOrderableClusterOptionsRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=DescribeOrderableClusterOptions&";
  if(m_clusterVersionHasBeenSet)
  {
    ss << "ClusterVersion=" << StringUtils::URLEncode(m_clusterVersion.c_str()) << "&";
  }
  if(m_nodeTypeHasBeenSet)
  {
    ss << "NodeType=" << StringUtils::URLEncode(m_nodeType.c_str()) << "&";
  }
  if(m_maxRecordsHasBeenSet)
  {
    ss << "MaxRecords=" << m_maxRecords << "&";
  }
  if(m_markerHasBeenSet)
  {
    ss << "Marker=" << StringUtils::URLEncode(m_marker.c_str()) << "&";
  }
  ss << "Version=2012-12-01";
  return ss.str();
}

