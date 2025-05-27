#pragma once

#define DRAW_SPHERE(Location) \
		if (GetWorld()) \
			DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Cyan, true);

#define DRAW_SPHERE_COLOR(Location, Color) \
		if (GetWorld()) \
			DrawDebugSphere(GetWorld(), Location, 8.f, 12, Color, false, 5.f);

#define DRAW_COLOR_SPHERE(Location, Color) \
		if (GetWorld()) \
			DrawDebugSphere(GetWorld(), Location, 25.f, 12, Color, true);

#define DRAW_SPHERE_SingleFrame(Location) \
		if (GetWorld()) \
			DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f); // false + -1: singleframe only

#define DRAW_LINE(Location, EndLocation) \
		if (GetWorld()) \
			DrawDebugLine(GetWorld(), Location, EndLocation, FColor::Red, true, -1.f, 0, 1.f);

#define DRAW_LINE_SingleFrame(Location, EndLocation) \
		if (GetWorld()) \
			DrawDebugLine(GetWorld(), Location, EndLocation, FColor::Red, false, -1.f, 0, 1.f);

#define DRAW_POINT(Location) \
		if (GetWorld()) \
			DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, true);

#define DRAW_POINT_SingleFrame(Location) \
		if (GetWorld()) \
			DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, false, -1.f);

#define DRAW_VECTOR(StartLocation, EndLocation) \
		if (GetWorld()) \
		{ \
			DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
			DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, true); \
		}
#define DRAW_VECTOR_SingleFrame(StartLocation, EndLocation) \
		if (GetWorld()) \
		{ \
			DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f); \
			DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, false, -1.f); \
		}

#define DRAW_BOX(Location) \
		if (GetWorld()) \
			DrawDebugBox(GetWorld(), Location, FVector(30.0f, 30.0f, 30.0f), GetActorQuat(), FColor::Cyan, true, 0.f, 10.0f);