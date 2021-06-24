#*******************************************************************************
# * Copyright (c) 2016 fortiss GmbH and Herwig Eichler, www.conmeleon.org
# * All rights reserved. This program and the accompanying materials
# * are made available under the terms of the Eclipse Public License v1.0
# * which accompanies this distribution, and is available at
# * http://www.eclipse.org/legal/epl-v10.html
# *
# * Contributors:
# *    Alois Zoitl and Herwig Eichler
# *******************************************************************************/ 
 
forte_add_module(CLASS2_DEVICE "implementation of extendable FB library based on Tiny cc and minyXml")

#forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#forte_add_link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
forte_add_link_library(dl mxml  tcc )
forte_add_definition("-DFORTE_SUPPORT_CLASS2DEV")
forte_add_sourcefile_hcpp(DynBasicFunctionBlock)
forte_add_sourcefile_hcpp(DynCompositeFunctionBlock)
forte_add_sourcefile_hcpp(DynFBTypeEntry)
forte_add_sourcefile_hcpp(StateNode)
forte_add_sourcefile_hcpp(XMLParser4BFB	)
forte_add_sourcefile_hcpp(XMLParser4CFB)
forte_add_sourcefile_hcpp(XMLParser4FB)


