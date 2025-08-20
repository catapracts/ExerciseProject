//
//  SecondView.swift
//  Test
//
//  Created by MacBook on 2025/08/20.
//

import Foundation
import SwiftUI

struct SecondView: View {
    var body: some View {
        VStack(spacing: 20) {
            Text("두 번째 화면입니다.")
                .font(.title)

            Image(systemName: "heart.fill")
                .resizable()
                .frame(width: 100, height: 100)
                .foregroundColor(.red)
        }
        .navigationTitle("두 번째 화면")
        .padding()
    }
}
