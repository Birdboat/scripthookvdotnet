#pragma once

#include "Model.hpp"
#include "Vector3.hpp"

namespace GTA
{
	ref class Blip;

	public ref class Entity abstract
	{
	public:
		Entity(int handle);

		[System::ObsoleteAttribute("Entity.ID is obsolete, please use Entity.Handle instead.")]
		property int ID
		{
			int get()
			{
				return Handle;
			}
		}
		property int Handle
		{
			int get();
		}
		property Blip ^CurrentBlip
		{
			Blip ^get();
		}
		property Math::Vector3 ForwardVector
		{
			Math::Vector3 get();
		}
		property bool FreezePosition
		{
			void set(bool value);
		}
		property float Heading
		{
			float get();
			void set(float value);
		}
		property int Health
		{
			int get();
			void set(int value);
		}
		property float HeightAboveGround
		{
			float get();
		}
		property bool IsAlive
		{
			bool get();
		}
		property bool IsDead
		{
			bool get();
		}
		property bool IsInAir
		{
			bool get();
		}
		property bool IsInWater
		{
			bool get();
		}
		property bool IsInvincible
		{
			void set(bool value);
		}
		property bool IsOccluded
		{
			bool get();
		}
		property bool IsOnFire
		{
			bool get();
		}
		property bool IsOnScreen
		{
			bool get();
		}
		property bool IsPersistent
		{
			bool get();
			void set(bool value);
		}
		property bool IsUpright
		{
			bool get();
		}
		property bool IsUpsideDown
		{
			bool get();
		}
		property bool IsVisible
		{
			bool get();
			void set(bool value);
		}
		property int MaxHealth
		{
			int get();
			void set(int value);
		}
		property GTA::Model Model
		{
			GTA::Model get();
		}
		property Math::Vector3 Position
		{
			Math::Vector3 get();
			void set(Math::Vector3 value);
		}
		property Math::Vector3 RightVector
		{
			Math::Vector3 get();
		}
		property Math::Vector3 Rotation
		{
			Math::Vector3 get();
			void set(Math::Vector3 value);
		}
		property Math::Vector3 UpVector
		{
			Math::Vector3 get();
		}
		property Math::Vector3 Velocity
		{
			Math::Vector3 get();
			void set(Math::Vector3 value);
		}

		bool IsInRangeOf(Math::Vector3 position, float range);
		bool IsInArea(Math::Vector3 pos1, Math::Vector3 pos2);
		bool IsInArea(Math::Vector3 pos1, Math::Vector3 pos2, float angle);
		bool IsNearEntity(Entity^ entity, Math::Vector3 distance);
		bool IsTouching(Entity ^entity);
		bool HasBeenDamagedBy(Entity ^entity);
		Math::Vector3 GetOffsetInWorldCoords(Math::Vector3 offset);

		bool IsAttached();
		void AttachTo(Entity^ entity, int boneIndex);
		void AttachTo(Entity^ entity, int boneIndex, Math::Vector3 position, Math::Vector3 rotation);
		void Detach();

		Blip ^AddBlip();

		void ApplyForce(Math::Vector3 direction);
		void ApplyForce(Math::Vector3 direction, Math::Vector3 rotation);
		void ApplyForceRelative(Math::Vector3 direction);
		void ApplyForceRelative(Math::Vector3 direction, Math::Vector3 rotation);

		void Delete();
		bool Exists();
		static bool Exists(Entity ^entity);
		void MarkAsNoLongerNeeded();
		virtual bool Equals(Entity ^entity);

		virtual int GetHashCode() override;
		static inline bool operator ==(Entity ^left, Entity ^right)
		{
			if (Object::ReferenceEquals(left, nullptr))
			{
				return Object::ReferenceEquals(right, nullptr);
			}

			return left->Equals(right);
		}
		static inline bool operator !=(Entity ^left, Entity ^right)
		{
			return !operator ==(left, right);
		}

	private:
		int mHandle;
	};
}